# dockersup

## Docker daemon configuration

Install docker  
$ curl -sSL https://get.docker.com/ | sh

Create the docker user group  
$ sudo groupadd docker

Create the supervision user  
$ sudo useradd dockersup

Add the supervision user to the docker group  
$ sudo usermod -aG docker dockersup

Reboot to apply system changes  
$ sudo reboot