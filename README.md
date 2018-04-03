# Cluster

This project aims to reproduce large-scale clusters' structure to a small teaching example using Raspberry Pi (10 of them). To illustratre how the cluster works, we used bruteforce.

![Cluster photo](https://i.imgur.com/5YEs3XY.jpg)

## Technologies

* Ansible for config deployement
* SLURM for cluster management
* Ganglia to monitor the Pi

## Project's structure

* "bruteforce" : small cpp application which bruteforces a password with a limited complexity ([a-z])

* cluster : contains all the deployement files for Ansible and the configuration for the nodes

* web inteface : is used to have a graphical feedback and be able to start hacking passwords from there : [gopicluster
 project](https://github.com/tbellembois/gopicluster)

## Cluster's structure

![Cluster's structure](https://i.imgur.com/R0mO7PR.png)

## Contributors

* Louis Turpinat : "Unix side" with Ansible, SLURM, Ganglia and all the networking part
* David Soares : "bruteforce" part
* Thomas Bellembois : [gopicluster](https://github.com/tbellembois/gopicluster)

## Acknowledgement

* [Thomas Bellembois](https://github.com/tbellembois/) : for all the advice and help he provided us during this project, thanks !
* Marc Chevaldonné : for giving us time to work on this project