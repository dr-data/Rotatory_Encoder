# Rotatory_Encoder
Read pulses from a rotatory encoder to get the angular position

I created these three codes to obtain the angular position of a rotary encoder.

The 1x code makes it possible to read an angular displacement for each pulse. It is the simplest reading of a rotary encoder, it is less precise but allows to have a higher revolution speed.

The 2x code makes it possible to read two angular displacements for each pulse. The interrupt routine is invoked twice more often so the maximum revolution speed is reduced. However, you double the accuracy of the reading.

The 4x code makes it possible to read four angular displacements for each pulse. The interrupt routine is invoked four times more often so the maximum revolution speed is reduced. However, you quadruple the accuracy of the reading.

The code must be chosen according to the desired precision and the maximum permited revolution speed.

Here is the reading scheme on the rotary encoder.

OutputA on the rotary encoder 0 1 1 0, 0 1 1 0, 0 1 1 0, 0 ...
OutputB on the rotary encoder 0 0 1 1, 0 0 1 1, 0 0 1 1, 0 ...

You notice that signal OutputB is phase-shifted by a quarter cycle on OutputA, which gives us four different states for a complete cycle.

00, 10, 11, 01, ... in one direction and 01, 11, 10, 00, ... in the other direction.

The change of state of one of the two signals indicates an angular displacement of a quarter of a pulse while the sequence determines the direction of rotation. This information is obtained by setting interrupts on an Arduino. There are several interruptions, for the Arduino Uno it is: Int0 = pin2 and Int1 = Pin3. It is possible to monitor only the change of state from 0 to 1, from 1 to 0 or simply any changes of state. With these variants, the code can be adjusted to increase the accuracy to the detriment of the number of treatments to be carried out.

The 1x code attempts to minimize the number of processes in order to increase the maximum allowed angular velocity. We are therefore interested in only one trigger per cycle. It was chosen to monitor OutputA only when passing a signal from 0 to 1 (RAISING). The routine validates the signal present on OutputB at this moment and it indicate the direction of rotation. Only one reading per cycle and a simple routine. The possible values are : 10 or 11 according to the direction of rotation.
