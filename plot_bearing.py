"""
============================================================
  MotorGuard - Bearing Spectrum Plot (healthy vs fault)
============================================================
Plots the envelope FFT of BOTH bearing files on top of each
other so you can SEE the 107 Hz outer-race fault peak appear
on the damaged bearing and be absent on the healthy one.

HOW TO USE:
  Put this on the Desktop next to 97.mat and OR007.mat,
  open it in IDLE, and press F5. A chart window opens.
============================================================
"""
import os
import numpy as np
from scipy.io import loadmat
from scipy.signal import hilbert
from scipy.fft import rfft, rfftfreq
import matplotlib.pyplot as plt

FS = 12000
RPM = 1797
N_BALLS, BALL_DIA, PITCH_DIA = 9, 0.3126, 1.537


def bpfo(rpm):
    fr = rpm / 60.0
    return (N_BALLS / 2) * fr * (1 - BALL_DIA / PITCH_DIA)


def load_signal(path):
    mat = loadmat(path)
    de = [k for k in mat.keys() if k.endswith("DE_time")]
    return mat[de[0]].ravel()


def envelope_spectrum(signal, fs):
    signal = signal - np.mean(signal)
    env = np.abs(hilbert(signal))
    env = env - np.mean(env)
    spectrum = np.abs(rfft(env)) / len(env)
    freqs = rfftfreq(len(env), 1 / fs)
    return freqs, spectrum


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    predicted = bpfo(RPM)

    healthy_sig = load_signal(os.path.join(here, "97.mat"))
    fault_sig = load_signal(os.path.join(here, "OR007.mat"))

    fh, sh = envelope_spectrum(healthy_sig, FS)
    ff, sf = envelope_spectrum(fault_sig, FS)

    band_h = fh <= 400
    band_f = ff <= 400

    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 7), sharex=True)

    ax1.plot(fh[band_h], sh[band_h], color="green", linewidth=0.8)
    ax1.axvline(predicted, color="red", linestyle="--",
                label="predicted BPFO = %.0f Hz" % predicted)
    ax1.set_title("Healthy bearing (97.mat) - no peak at fault frequency")
    ax1.set_ylabel("Envelope magnitude")
    ax1.legend()

    ax2.plot(ff[band_f], sf[band_f], color="darkorange", linewidth=0.8)
    ax2.axvline(predicted, color="red", linestyle="--",
                label="predicted BPFO = %.0f Hz" % predicted)
    ax2.set_title("Faulty bearing (OR007.mat) - clear peak at 107 Hz")
    ax2.set_xlabel("Frequency (Hz)")
    ax2.set_ylabel("Envelope magnitude")
    ax2.legend()

    plt.tight_layout()
    plt.savefig(os.path.join(here, "bearing_comparison.png"), dpi=130)
    print("Chart saved as bearing_comparison.png")
    plt.show()


if __name__ == "__main__":
    main()
