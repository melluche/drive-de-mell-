import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# --- Paramètres du composant et de la constante de temps ---
R = 4.7e3      # Résistance en Ohms (4.7 kOhm)
C = 100e-9     # Capacité en Farads (100 nF)
T_RC = R * C   # Constante de temps tau = RC en secondes

# --- Paramètres du signal et de la simulation ---
F_signal = 1e3     # Fréquence du signal (Hz)
T_signal = 1 / F_signal  # Période du signal (5 ms)
Duree_simu = 5 * T_signal  # Durée totale de la simulation (5 périodes)

Fe = 5000 * F_signal # Fréquence d'échantillonnage (doit être très élevée)
Te = 1 / Fe          # Pas de temps
Amplitude = 5  # Amplitude crête du signal (10V crête à crête )

# Vecteur temps
t = np.arange(0, Duree_simu, Te)

# --- 1. Signal Carré (Créneau) ---
Ve_carre = Amplitude * signal.square(2 * np.pi * F_signal * t)

# --- 2. Signal Triangle ---
Ve_triangle = Amplitude * signal.sawtooth(2 * np.pi * F_signal * t, width=0.5)

# --- Fonction de filtrage (Intégration numérique) ---
def integrateur_numerique(Ve, Te, RC, Vs0=0):
    """ méthode d'Euler."""
    Vs = np.zeros_like(Ve)
    Vs[0] = Vs0  # Condition initiale
    gain = Te / RC
    
    for n in range(1, len(Ve)):
        # Équation de récurrence : Vs[n] = Vs[n-1] + (Te/RC) * Ve[n-1]
        Vs[n] = Vs[n-1] + gain * Ve[n-1] 
    return Vs

# --- Application du filtre ---
Vs_carre = -integrateur_numerique(Ve_carre, Te, T_RC) +2.5
Vs_triangle = -integrateur_numerique(Ve_triangle, Te, T_RC)

# --- Affichage des résultats ---
plt.figure(figsize=(12, 8))

# 1. Réponse au signal Carré 
plt.subplot(2, 1, 1)
plt.plot(t * 1e3, Ve_carre, label='Entrée Carré $V_e(t)$ ($\pm 5V$)', color='blue')
plt.plot(t * 1e3, Vs_carre, label='Sortie Intégrateur $V_s(t)$', color='red', linewidth=2)
plt.title(r'Réponse au Signal Carré')

plt.xlabel('Temps (ms)')
plt.ylabel('Tension (V)')
plt.legend()
plt.grid(True)
plt.axhline(0, color='black', linestyle='--', linewidth=0.5)

# 2. Réponse au signal Triangle
plt.subplot(2, 1, 2)
plt.plot(t * 1e3, Ve_triangle, label='Entrée Triangle $V_e(t)$ ($\pm 5V$)', color='green')
plt.plot(t * 1e3, Vs_triangle, label='Sortie Intégrateur $V_s(t)$ ', color='orange', linewidth=2)

plt.title(r'Réponse au Signal Triangle')

plt.xlabel('Temps (ms)')
plt.ylabel('Tension (V)')
plt.legend()
plt.grid(True)
plt.axhline(0, color='black', linestyle='--', linewidth=0.5)

plt.tight_layout()
plt.show()
