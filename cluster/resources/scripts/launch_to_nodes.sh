#!/bin/bash
PASSWORD=$1

PARTITION=$2

case $2 in
   1)
      PARTITION="one_node"
      ;;
   4)
      PARTITION="four_nodes"
      ;;
   8)
      PARTITION="all"
      ;;
   *)
      PARTITION="all"
     ;;
esac


echo "calling program with password $PASSWORD" | tee /tmp/launch_to_nodes.log
for l1 in {a..z} ; do
    for l2 in echo {a..z} ; do
        echo "l1l2: $l1$l2" | tee -a /tmp/launch_to_nodes.log
        /usr/bin/sbatch --partition="$PARTITION" -N1 /opt/slurm/hack.sh $l1$l2 $PASSWORD | tee -a /tmp/launch_to_nodes.log
    done
done

