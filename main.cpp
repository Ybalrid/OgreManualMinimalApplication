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
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
    Ogre::SceneManager* smgr = root->createSceneManager("DefaultSceneManager", "Le Scene Manager");
    Ogre::Camera* cam = smgr->createCamera("camera");
    Ogre::Viewport* vp = window->addViewport(cam);
    //Cette couleur n'est pas Gay du tout : 
    vp->setBackgroundColour(Ogre::ColourValue(1,0,1));

    while(true)
        root->renderOneFrame();
    return 0;
}
