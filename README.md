# Cluster

This project aims to reproduce large-scale clusters' structure to a small teaching example using Raspberry Pi (10 of them). To illustratre how to cluster works, we used a bruteforce example.

![Cluster photo](https://i.imgur.com/5YEs3XY.jpg)

## Technologies

* Ansible for config deployement
* SLURM for cluster management
* Ganglia to monitor the Pi

## Project's structure

* "bruteforce" : small cpp application which bruteforce a password with a limited complexity ([a-z])

* cluster : contains all the deployement files for Ansible and the configuration for the nodes

## Cluster's structure

![Cluster's structure](https://i.imgur.com/R0mO7PR.png)
