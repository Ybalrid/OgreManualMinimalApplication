#include <Ogre.h>

int main()
{
    Ogre::Root* root = new Ogre::Root("plugins.cfg", "ogre.cfg", "ogre.log");
    
    //va chercher la config de ogre dans ogre.cfg
    if(!root->restoreConfig())
        //affiche la fenetre de config de ogre
        if(!root->showConfigDialog()) 
            //explosion nucléaire
            return -1;

    
    Ogre::RenderWindow* window = root->initialise(true, "The most epic window of the universe");


    //ICI charger les resources
    //----------sinbad, l'ogre dans le sdk d'ogre...
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("./media/Sinbad.zip","Zip");

    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
    Ogre::SceneManager* smgr = root->createSceneManager("DefaultSceneManager", "Le Scene Manager");
    Ogre::Camera* cam = smgr->createCamera("camera");
    Ogre::Viewport* vp = window->addViewport(cam);
    cam->setNearClipDistance(0.01);
    cam->setAspectRatio((float)vp->getActualWidth()/(float)vp->getActualHeight());
    cam->setAutoAspectRatio(true);
    //Cette couleur n'est pas Gay du tout : 
    vp->setBackgroundColour(Ogre::ColourValue(1,0,1));


    //ICI ajouter des choses dans le scene manager
    smgr->setAmbientLight(Ogre::ColourValue(.5,.5,.5));

    Ogre::SceneNode * node = smgr->getRootSceneNode()->createChildSceneNode();
    Ogre::Entity* ent = smgr->createEntity("Sinbad.mesh");
    node->attachObject(ent);

    cam->setPosition(0,0,10);
    cam->lookAt(Ogre::Vector3::ZERO);


    bool run(true);
    while(run)
    {
        
         Ogre::WindowEventUtilities::messagePump();
         root->renderOneFrame();
         if(window->isClosed())
             run=false;
    }

    delete root;
    return 0;
}
