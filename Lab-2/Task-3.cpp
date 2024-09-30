#include <iostream>
using namespace std;

bool** create_network(){
    bool** network = new bool*[5];
    for (size_t i = 0; i < 5; i++){
        network[i] = new bool[5]{false};
    }
    network[0][1] = true; network[0][3] = true;
    network[0][4] = true; network[1][0] = true; network[1][2] = true;
    network[1][4] = true;
    network[2][1] = true; network[3][0] = true;
    network[3][4] = true; network[4][0] = true; network[4][1] = true;
    network[4][3] = true;
    return network;
}
void display(bool** network){
    cout << "   ";
    for (size_t j = 0; j < 5; j++){
        cout << j << "   ";
    }
    cout << endl;
    for (size_t i = 0; i < 5; i++){
        cout << i << " ";
        for (size_t j = 0; j < 5; j++){
            cout << "[" << network[i][j] << "] ";
        }
        cout << endl;
    }
}
void checkMutualFriend(bool** network, int personA, int personB){
    bool mutual = false;
    int commonFriend;
    for (size_t i = 0; i < 5; i++){
        if (network[personA][i] && network[personB][i]){
            mutual = true;
            commonFriend = i;
        }
    }
    if (mutual) cout << personA << " & " << personB << " have a mutual friend: " << commonFriend << endl;
    else cout << "No mutual friend found of " << personA << " & " << personB << endl;
}

int main(){
    bool** socialGrid = create_network();
    display(socialGrid);
    checkMutualFriend(socialGrid, 1, 4); 
    for (size_t i = 0; i < 5; i++){
        delete[] socialGrid[i];
    }
    delete[] socialGrid;

    return 0;
}