#include <stdio.h>
#include <math.h>
#include <time.h>
#include "stringlib.h"

// Declare Subroutines
void read_cfg_file(int *, double *, double *, char *, char *, int *, int *, double *);
void write_xyz_step(double **, int, int, double, FILE *);
void init_positions(double **, int, double *);
double total_pair_energy(double **, int, double, double**);
void atom_pair_energy(double **, int, double, int, double *);
double lennard_jones(double *, double *, double);
double sum(double*, int);

static double kB = 1.9872041E-3; // actually R in units of kcal/mol/K
static double eps = 0.210849;    // units of kcal/mol
static double sigma = 3.345;  // units of angstroms
static double sigma6 = 1400.80193382; // units of angstroms^6

//Main Program
int main() {

	int nAtoms;     // Number of atoms  in config file
	double temp;     // temperature from config file
	double box;      // cubic box size 
	int nIter;      // number of MD iterations from config file
	int deltaWrite; // how often to write coordinates and log info in MD 
	double deltaX;   // how big to make the translation attempt???

	char trajFileName[1024];  // output trajectory file name assinged in config file
	char logFileName[1024];   // output log file name assigned in config file

	double **coord;  // coordinates of particles 
	double **atomEnergy; // energy per atom

	int i, j, k, atom1;    // genereic indeces 
	int iter;       // MD iteration
	int atom;       // MD selected atom 
	double energy;   // energy of the system
	double delta[3]; // added position
	double kBT;
	double *newEnergy;
	double deltaE;
	int acceptedMoves;
		
	FILE *xyzOut;
	FILE *logOut;      // log output file

	time_t startTime;   // initial clock time
	time_t stopTime;    // final clock time
	time_t routineStartTime; // start time for a routine
	time_t routineStopTime;  // stop time for a routine
	double timeSpent; // amount of time in seconds 
	double energyCalcTime; // 

	// initialize job timing
	startTime = clock();

	// read config data from standard in
	read_cfg_file(&nAtoms, &temp, &box, trajFileName, logFileName, &nIter, &deltaWrite, &deltaX);
	kBT = kB*temp;
	printf("kB*T=%f\n",kBT);
	printf("nAtoms=%f\n",nAtoms);
	printf("temp=%f\n",temp);
	printf("box=%f\n",box);
	printf("nIter=%f\n",nIter);
	printf("deltax=%f\n",deltawrite);
	printf("deltax=%f\n",deltax);

}
