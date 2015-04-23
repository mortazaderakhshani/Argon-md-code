List of Necessary files:
liquid_argon_md.c
stringlib.c
striglib.h



To compile:
gcc liquid_argon_md.c -o liquid_argon_md.x

To run:
./liquid_argon_mc.x < [config file] > config.log

Configuration file should contain values for the following keywords:

trajFile [trajectory file name]
logFile [energy log information file name]
temperature [temperature value (double)]
nAtoms [number of atoms (int)]
nIter [number of MD interations (int)]
deltaWrite [how often to write trajectory and energy info (int)]
deltaX [size of possible MC translation (double)]


