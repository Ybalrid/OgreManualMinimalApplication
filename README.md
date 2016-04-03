# OgreManualMinimalApplication
![Screenshot](/screenshot.png)


Dépot vide d'exemple avec un fichier c++ et un makefile qui compile une aplication "de base" lancée avec Ogre sous Ubnutu 14.04


Avant de pouvoir compiler; installer les dépendances :
```sudo apt-get install libogre-1.9-dev g++ libboost-dev libboost-system-dev libois-dev libpthread-stubs0-dev```


Avant de pouvoir executer le programme faire :
```cp /usr/lib/x86_64-linux-gnu/OGRE-1.9.0/RenderSystem_GL.so* ./plugin/```


pour compiler, juste lancer "make"

pour tester le programme, juste lancer ./test
