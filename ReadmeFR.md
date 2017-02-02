J’ai crée ces trois codes pour obtenir la position angulaire d’un encodeur rotatif.

Le code 1x permet de lire un déplacement angulaire pour chaque pulsation. Il s’agit de la lecture la plus simple d’un encodeur rotatif, elle est moins précise mais permet d’avoir une vitesse de révolution plus grande.

Le code 2x permet de lire deux déplacements angulaires pour chaque pulsation. La routine d’interruption est invoquée deux fois plus souvent donc la vitesse de révolution maximale en est réduite. Toutefois, vous doublez la précision de la lecture.

Le code 4x permet de lire quatre déplacements angulaires pour chaque pulsation. La routine d’interruption est invoquée quatre fois plus souvent donc la vitesse de révolution maximale en est réduite. Toutefois, vous quadruplez la précision de la lecture.

Il faut choisir le code en fonction de la précision souhaité ainsi que la vitesse de révolution maximale permise.

Voici le schéma de lecture sur l’encodeur rotatif.
      __       __      __
__|   |__|   |__|   |__     Output A sur l’encodeur rotatif
         __       __      __
   __|   |__|   |__|   |__  Output B sur l’encodeur rotatif

Vous remarquez que le signal B est déphasé d’un quart de cycle sur le signal A ce qui nous donne quatre états différent pour un cycle complet.

00, 10, 11, 01, … dans un sens et 01, 11, 10, 00, … dans l’autre sens.

Le changement d’état d’un des deux signaux indique un déplacement angulaire d’un quart de pulsation alors que la séquence détermine le sens de rotation. On obtient ces informations en paramétrant les interruptions sur un Arduino. Il existe plusieurs interruptions, pour le Arduino Uno c’est : Int0 = pin2 et Int1 = Pin3. On peut surveiller uniquement le changement d’état de 0 à 1, de 1 à 0 ou simplement tous changements d’état. Avec ces variantes on pourra ajuster le code pour augmenter la précision au détriment du nombre de traitements à effectuer.

Le code 1x tente de minimiser le nombre de traitements afin d’accroitre la vitesse angulaire maximale permise. On s’intéresse donc à un seul déclencheur par cycle. On a choisi de surveiller OutputA seulement lors du passage d’un signal de 0 à 1 (RAISING). La routine valide le signal présent sur OutputB à ce moment afin de déterminer le sens de rotation. Une seule lecture par cycle et une routine simple à exécuter. Les valeurs possibles sont 10 ou 11 selon le sens de rotation.


