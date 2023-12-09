//
// Created by Marthel Rodriguez on 11/20/23.
//

#ifndef SFMLTEMPLATE_FILEITEM_H
#define SFMLTEMPLATE_FILEITEM_H

//FileItem for FileTree.
#include <SFML/Graphics.hpp>
#include "./NaryTree/TreeNode.h"
#include "../Components/GUIComponent.h"

//public item: it's going to be of type Item<FileNode>
class FileItem : public GUIComponent {

private:
    TreeNode<std::string> data;
    sf::Text text;
    sf::RectangleShape icon;
    sf::RectangleShape container;
    //this is the folder or file icon
    ///TODO: padding must be incremented based of the depth of the item.
    float padding = 5;

    //set the texture to the icon rectangleShape
    void setIcon(sf::Texture &icon);
public:
    //Constructors
    FileItem();
    FileItem(std::string text, sf::Vector2f size, sf::Vector2f position);
    FileItem(TreeNode<std::string> &data, sf::Vector2f size, sf::Vector2f position);
//    FileItem(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position);

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the size of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    void setPosition(sf::Vector2f pos);
    //uses an enum to change the icon to a folder or file
    std::string getFileName();
    int getDepth();
    std::filesystem::file_type &getFileType();
    std::string &getPath();

    //TODO: when clicking one, change the background color.
    void setFocus();

    void update() override;
    /**
     * getters
     **/

};


#endif //SFMLTEMPLATE_FILEITEM_H
