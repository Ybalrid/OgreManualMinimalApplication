#include <iostream>
#include <Ogre.h>
#include <math.h>

void anim(long time, Ogre::SceneNode* node)
{
    Ogre::Quaternion q(Ogre::Radian(0.5*3.14*sin(float(time)/1000.0f)), Ogre::Vector3::UNIT_Y);
    node->setOrientation(q);
}

int main()
{
    //Initialise un objet instance de la classe principale de Ogre (Ogre::Root)
    Ogre::Root* root = new Ogre::Root("plugins.cfg", "ogre.cfg", "ogre.log");
    
    //va chercher la config de ogre dans ogre.cfg
    if(!root->restoreConfig())
        //affiche la fenetre de config de ogre
        if(!root->showConfigDialog()) 
            //explosion nucléaire
            return -1;

    //Initialise une fenetre
    Ogre::RenderWindow* window = root->initialise(true, "The most epic window of the universe");


    //ICI charger les resources
    //----------sinbad, l'ogre dans le sdk d'ogre...
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("./media/Sinbad.zip","Zip");
    //Initialise toutes les resources chargés
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
    
    
    //Déclare un scème manager (graphe de scene, basiquement un arbre contneant des noeud représentant la scene
    Ogre::SceneManager* smgr = root->createSceneManager("DefaultSceneManager", "Le Scene Manager");
    
    //Ajoute une caméra dans la scene
    Ogre::Camera* cam = smgr->createCamera("camera");
    
    //Ajoute un viewport dans la fenetre, et attache la caméra dessus
    Ogre::Viewport* vp = window->addViewport(cam);
    
    //Distance du plan de clip "proche" à 0.01
    cam->setNearClipDistance(0.01);
    
    //Initialise l'aspect ratio de la caméra
    cam->setAspectRatio((float)vp->getActualWidth()/(float)vp->getActualHeight());
    cam->setAutoAspectRatio(true);
    
    //Ajoute une couleur de fond "parce que"
    vp->setBackgroundColour(Ogre::ColourValue(1,0,1));


    //ICI ajouter des choses dans le scene manager
    
    //éclairaige d'ambiance gris moyen
    smgr->setAmbientLight(Ogre::ColourValue(1,1,1));

    //Ajoute un objet dans la scene (ici Sinbad, la mascotte de Ogre)
    //créé un noeud fils du noeud principal
    Ogre::SceneNode * node = smgr->getRootSceneNode()->createChildSceneNode();
    
    //Créé une entité a partir de l'objet 3D
    Ogre::Entity* ent = smgr->createEntity("Sinbad.mesh");
    
    //Attache l'objet au noeud du graphe de scene
    node->attachObject(ent);
    
    //Place la caméra 10 unité vers l'axe Z (= axe qui sort de l'écran)
    cam->setPosition(0,0,10);
    
    //fait regarder la camera le point à l'origine de la scene
    cam->lookAt(Ogre::Vector3::ZERO);


    //Boolean pour éviter de faire une boucle infinie
    bool run(true);

    //Boucle de rendu
    while(run)
    {
        //std::cout << window->getLastFPS() << std::endl;        
        anim(root->getTimer()->getMilliseconds(), node);
        //Lit les "messages" reçu par la fenetre
        Ogre::WindowEventUtilities::messagePump();
        //Calcule et affiche une frame
        root->renderOneFrame();
        //Si on a cliqué sur la croix sur la fenetre
        if(window->isClosed())
            //Couper la boucle
            run=false;

    }

    //Désalouer Ogre de la mémoire
    delete root;
    
    //Retourner 0 au système car tout c'est bien passé
    return 0;
}
