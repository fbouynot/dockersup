# dockersup


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