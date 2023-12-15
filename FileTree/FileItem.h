//
// Created by Marthel Rodriguez on 11/20/23.
//

#ifndef SFMLTEMPLATE_FILEITEM_H
#define SFMLTEMPLATE_FILEITEM_H

//FileItem for FileTree.
#include <SFML/Graphics.hpp>
#include "./NaryTree/TreeNode.h"
#include "../Components/GUIComponent.h"
#include "../Components/ContainerInterface.h"
#include "../Container/Container.h"
#include "../Text/Text.h"
#include "../Item/ItemList.h"
#include <string>
class FileItem : public GUIComponent, public ContainerInterface {

private:
    TreeNode<std::string> data;
    Text fileItemText;
    Container icon;
    Container fileItemContainer;
    //this is the folder or file icon
    ///TODO: padding must be incremented based of the depth of the item.
    float padding = 5;



    // TODO: create a setter that will pass a static method which will run to read
    //the path of the file to unlock the pokemon. GO and start with a base template.
    void (*pFunct)();

public:
    //Constructors
    FileItem();

    FileItem(std::string text, sf::Vector2f size, sf::Vector2f position);

    FileItem(TreeNode<std::string> &data, sf::Vector2f size, sf::Vector2f position);
//    FileItem(Image::image icon, std::string fileItemText, sf::Vector2f size, sf::Vector2f position);

    ///GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);

    void update() override;

    int getDepth();

    std::filesystem::file_type &getFileType();

    std::string &getPath();

    //TODO: when clicking one, change the background color.
    void setFocus();


    //set the texture to the icon rectangleShape
    void setIconTexture(const sf::Texture &iconTexture);

    bool getIsFocused();

    std::string getFileName();

//    //uses an enum to change the icon to a folder or file

    sf::Vector2f getPosition() override;
    sf::Vector2f getPosition() const;

    sf::Vector2f getSize() override;

    sf::FloatRect getLocalBounds() const override;

    sf::FloatRect getGlobalBounds() const override;

    void setOrigin(sf::Vector2f &origin) override;

    void setPosition(const sf::Vector2f &pos) override;

    void setFillColor(const sf::Color &color) override;

    void setTexture(const sf::Texture &texture) override;

    void setSize(sf::Vector2f size) override;

    void setOutlineThickness(float outlineThickness) override;

    void setOutlineColor(const sf::Color &color) override;

    void setChildren(const ItemList<FileItem> &children);
};


#endif //SFMLTEMPLATE_FILEITEM_H
