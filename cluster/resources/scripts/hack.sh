#!/bin/bash
#SBATCH --job-name=password_hacking    # Job name
#SBATCH --time=00:01:00              # Time limit hrs:min:sec
#SBATCH --ntasks=1
#SBATCH --output=/srv/shared/log/$SLURM_JOB_ID

pwd; hostname; date

echo "Running hack for bruteforce password hacking"
echo "Parameters: $1 $2 $SLURM_JOB_ID"
/opt/slurm/crack fancybruteforce $1 $2 $SLURM_JOB_ID
echo "Done"
date
