import os
import numpy as np
from scipy.io import loadmat
from scipy.signal import hilbert
from scipy.fft import rfft, rfftfreq

FILENAME = "97.mat"
FS = 12000
RPM = 1797

N_BALLS = 9
BALL_DIA = 0.3126
PITCH_DIA = 1.537


def bpfo(rpm):
    fr = rpm / 60.0
    return (N_BALLS / 2) * fr * (1 - BALL_DIA / PITCH_DIA)


def load_signal(path):
    mat = loadmat(path)
    de_keys = [k for k in mat.keys() if k.endswith("DE_time")]
    if not de_keys:
        raise ValueError("No drive-end (DE_time) data found in this file.")
    return mat[de_keys[0]].ravel()


def envelope_spectrum(signal, fs):
    signal = signal - np.mean(signal)
    env = np.abs(hilbert(signal))
    env = env - np.mean(env)
    spectrum = np.abs(rfft(env)) / len(env)
    freqs = rfftfreq(len(env), 1 / fs)
    return freqs, spectrum


def dominant_peak(freqs, spectrum, fmin=20, fmax=400):
    band = (freqs >= fmin) & (freqs <= fmax)
    fb, sb = freqs[band], spectrum[band]
    i = np.argmax(sb)
    return fb[i]


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    path = os.path.join(here, FILENAME)
    if not os.path.exists(path):
        print("FILE NOT FOUND:", path)
        return
    print("=" * 50)
    print("  Analysing:", FILENAME)
    print("=" * 50)
    signal = load_signal(path)
    print("Samples loaded:", len(signal))
    print("Duration:", round(len(signal) / FS, 2), "seconds")
    predicted = bpfo(RPM)
    print("\nPhysics prediction (BPFO):", round(predicted, 1), "Hz")
    freqs, spec = envelope_spectrum(signal, FS)
    detected = dominant_peak(freqs, spec)
    print("FFT detected peak:        ", round(detected, 1), "Hz")
    error = abs(detected - predicted) / predicted * 100
    print("Difference:               ", round(error, 1), "%")
    print("\n" + "-" * 50)
    if error < 5:
        print("RESULT: MATCH - outer-race fault frequency present.")
    else:
        print("RESULT: NO MATCH - no outer-race fault at this frequency.")
        print("(Expected for a healthy bearing.)")
    print("-" * 50)


if __name__ == "__main__":
    main()
