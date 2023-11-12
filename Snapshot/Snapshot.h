//
// Created by Marthel Rodriguez on 11/11/23.
//

#ifndef SFMLTEMPLATE_SNAPSHOT_H
#define SFMLTEMPLATE_SNAPSHOT_H

#include <list>
#include <string>

class Snapshot {
private:
    std::string snapshotString;
public:
    // createSnapshot
    void setStringSnapshot(std::string &str);
    std::string getStringSnapshot();
};

#endif //SFMLTEMPLATE_SNAPSHOT_H
