# dockersup

This is a container monitoring software.  
It displays the container runing or inactive container images on the target host.


## Release

[dockersup-0.9-beta](https://github.com/fbouynot/dockersup/releases/tag/v0.9-beta)


## Disclaimer

At the time of writing, there is a bug on the sever side of the software causing it to crash on the second query.
The infinite loop maintaining the server in listening state stops when we use a free(var_msg).

Besides, the high number of files is a design desicion in order to ease the burden of collaborative work.

## Software compilation

We recomand the use of Clion.
https://www.jetbrains.com/clion/download



## Docker daemon configuration

Install docker  
```
$ curl -sSL https://get.docker.com/ | sh
```

Create the docker user group  
```
$ sudo groupadd docker
```

Add the current user  
```
$ sudo usermod -aG docker ${USER}
```
 
(Optional) Create the supervision user  
```
$ sudo useradd dockersup
```

(Optional) Add the supervision user to the docker group  
```
$ sudo usermod -aG docker  dockersup
```

Reboot to apply system changes  
```
$ sudo reboot
```
