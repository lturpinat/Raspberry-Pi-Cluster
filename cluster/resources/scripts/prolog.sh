#!/bin/bash
DIR=/srv/shared
HOSTNAME=$(hostname)
WEB_SERVER="10.0.0.9:8080"
NODE_ID=$(echo $HOSTNAME | grep -o '[0-9]*')
LOG="/srv/shared/log/$SLURM_JOB_ID"

# Send job ready with websocket
echo "Calling prolog for $SLURM_JOB_ID" > $LOG
echo "Sending this request : http://$WEB_SERVER/job/start?jobid=$SLURM_JOB_ID&node=$NODE_ID" >> $LOG
/usr/bin/curl --noproxy "*" "http://$WEB_SERVER/job/start?jobid=$SLURM_JOB_ID&node=$NODE_ID"
echo "Sent" >> $LOG
