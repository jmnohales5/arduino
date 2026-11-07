# Arduino

Sketches para un kit RFID Starter compatible con **Arduino UNO R3** (clon con chip USB-serie CH340).

Cada carpeta es un sketch independiente (`Nombre/Nombre.ino`).

## Sketches

| Carpeta | Descripción |
|---------|-------------|
| [Blink](Blink/Blink.ino) | Parpadeo del LED integrado (pin 13, marcado como "L") cada 500 ms |
| [Led](Led/Led.ino) | Enciende un LED externo conectado al pin 2 |
| [LedBlink](LedBlink/LedBlink.ino) | Hace parpadear un LED externo conectado al pin 2 cada 500 ms |

## Montaje del LED externo (Led y LedBlink)

```
Pin 2 ──[resistencia 1 kΩ]──(pata larga) LED (pata corta)── GND
```

- La **pata larga** del LED (ánodo, +) va hacia el pin 2, a través de la resistencia.
- La **pata corta** (cátodo, −) va a un pin `GND`.
- La resistencia es obligatoria: sin ella el LED consume demasiada corriente y puede dañarse, igual que el pin.
- Con 1 kΩ un LED azul brilla algo menos de lo normal. Con 220–330 Ω el brillo es mayor.

## Entorno

- Placa: Arduino UNO R3 (clon), FQBN `arduino:avr:uno`
- Equipo: MacBook Air 11" (Early 2014), macOS Big Sur
- Herramienta: [`arduino-cli`](https://arduino.github.io/arduino-cli/) **1.2.2**
  - Las versiones más nuevas (p. ej. 1.5.x) no funcionan en Big Sur (`SecTrustCopyCertificateChain` no encontrado).
- Puerto serie habitual: `/dev/cu.usbserial-14110` (puede cambiar; compruébalo con `arduino-cli board list` o `ls /dev/cu.*`)

## Comandos

```bash
# Instalar el núcleo de la Uno (una sola vez)
arduino-cli core update-index
arduino-cli core install arduino:avr

# Compilar (sustituye LedBlink por el sketch que quieras)
arduino-cli compile --fqbn arduino:avr:uno LedBlink

# Subir a la placa
arduino-cli upload -p /dev/cu.usbserial-14110 --fqbn arduino:avr:uno LedBlink

# Monitor serie
arduino-cli monitor -p /dev/cu.usbserial-14110 -c baudrate=9600
```

## Librerías

```bash
arduino-cli lib install MFRC522   # módulo RFID RC522
```

## Próximos pasos

- [ ] Pulsador con `INPUT_PULLUP`
- [ ] Monitor serie
- [ ] Brillo variable con PWM (pines `~`)
- [ ] Lector RFID RC522
