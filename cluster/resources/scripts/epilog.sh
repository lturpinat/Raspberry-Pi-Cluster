#!/bin/bash
DIR=/srv/shared
HOSTNAME=$(hostname)
FILE="$DIR/$HOSTNAME""_""$SLURM_JOB_ID"
WEB_SERVER="10.0.0.9:8080"
NODE_ID=$(echo $HOSTNAME | grep -o '[0-9]*')

if [ ! -f $FILE  ] ; then
    exit
fi

if [ "$(head -n 1 $FILE)" = "OK" ] ; then
    ssh root@pischeduler "scancel -u root"
    FOUND_PASSWORD=$(sed -n 2p $FILE)
    curl --noproxy "*" "http://$WEB_SERVER/job/stop?jobid=$SLURM_JOB_ID&node=$NODE_ID&result=ok&pass=$FOUND_PASSWORD"
else
    curl --noproxy "*" "http://$WEB_SERVER/job/stop?jobid=$SLURM_JOB_ID&node=$NODE_ID&result=ko"
fi
