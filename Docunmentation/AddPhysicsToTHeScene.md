# Add Physics to the World

In ```GameScene.hpp```, add a new Layer*:

```c++
Layer* metaLayer;
```

---

In ```GameScene.cpp```, add the code above to add PhysicsBody to the metaLayer:

```c++
	for (int i = 0; i < mapMe->getMapSize().width; ++i){
        for (int j = 0; j < mapMe->getMapSize().height; ++j){
            if (meta->getTileGIDAt(Vec2(i, j)) != 0) {
                Sprite* tile = Sprite::create("Blocks.png");
                tile->setScale(mapMe->getTileSize().width / tile->getContentSize().width,
                               mapMe->getTileSize().height / tile->getContentSize().height);
                PhysicsBody* tileBody = PhysicsBody::createBox(tile->getContentSize());
                tile->setPhysicsBody(tileBody);
                tile->setVisible(false);
                tileBody->setDynamic(false);
                tileBody->getShape(0)->setRestitution(0.0f);
                tileBody->getShape(0)->setFriction(0.5f);
                tile->setPosition(Vec2(i * mapMe->getTileSize().width + 16, (mapMe->getMapSize().height - j) * mapMe->getTileSize().height - 16));
                this->metaLayer->addChild(tile);
            }
        }
    }
```

