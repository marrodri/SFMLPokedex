//
// Created by Marthel Rodriguez on 11/20/23.
//

#ifndef SFMLTEMPLATE_FILENODE_H
#define SFMLTEMPLATE_FILENODE_H

#include "../Components/GUIComponent.h"
#include "FileItem.h"
#include <set>
class FileNode : public GUIComponent{
private:
    //This is the data represented in the tree
    FileItem data;

    //this is all the child nodes in the tree
    std::set<FileNode*> children;

    //this tells the draw function whether or not to show the node's children
    //this is done by toggling a state on and off
    void toggleChlidren();

    //this is called in the draw function to reposition the children so they
    //are indented and below the parent.
    void reposition() const;
public:
    // this is so I can use the iterator for the children map publicly
    typedef typename std::set<FileNode*>::iterator iterator;
    FileNode();
    FileNode(const std::string &text, sf::Vector2f size, sf::Vector2f position);
    FileNode(TreeNode<std::string> &data, sf::Vector2f size, sf::Vector2f position);
    FileNode(sf::Image image_icon, std::string &text, sf::Vector2f size, sf::Vector2f position);

    /*
     * setter
     * */
    void setData(const FileItem &data);
    void setPosition(const sf::Vector2f position);
    void setChildren(const std::set<FileNode*> &children);
    //does nothing now
    sf::FloatRect getGlobalBounds();
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;
    //getters and setters
    FileItem &getData();

    std::set<FileNode*>&getChildren();


    /**
     * GUI Component
     * */
    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //This is not currently used
//    virtual void applySnapshot(const Snapshot& snapshot);
    //does nothing now
//    virtual Snapshot& getSnapshot();

    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //does nothing now
    virtual void update();




    //iterators
    iterator begin();
    iterator end();

};


#endif //SFMLTEMPLATE_FILENODE_H
