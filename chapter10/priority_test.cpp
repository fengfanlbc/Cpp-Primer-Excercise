#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
    int x, y;
    Node(int a = 0, int b = 0): x(a), y(b){}
};
bool operator<(Node a, Node b){
        if(a.x == b.x)return a.y < b.y;
        return a.x < b.y;
}

bool operator>(Node a, Node b){
        if(a.x == b.x)return a.y > b.y;
        return a.x > b.y;
}

int main(int argc, char const *argv[])
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v = {1,3,4,5,1,2,3,89,34,22};
    for(auto s : v){
        pq.push(s);
    }

    while(!pq.empty()){
        cout << pq.top()<< " " ;
        pq.pop();

    }
    cout << endl;

    priority_queue<Node,vector<Node>, greater<Node>> q;
    for( int i= 0; i< 10; ++i )
    q.push( Node( rand(), rand() ) );
    while( !q.empty() ){
        cout << q.top().x << ' ' << q.top().y << endl;
        q.pop();
    }

    return 0; 
}
// #include <iostream>
// #include <queue>
// using namespace std;
// struct Node{
//     int x, y;
//     Node( int a= 0, int b= 0 ):
//         x(a), y(b) {}
// };
// bool operator>( Node a, Node b ){//返回true，a的优先级大于b
//     //x大的排在队前部；x相同时，y大的排在队前部
//     if( a.x== b.x ) return a.y> b.y;
//     return a.x> b.x;
// }
// int main(){
//     priority_queue<Node,vector<Node>,greater<Node> > q;
//     for( int i= 0; i< 10; ++i )
//     q.push( Node( rand(), rand() ) );
//     while( !q.empty() ){
//         cout << q.top().x << ' ' << q.top().y << endl;
//         q.pop();
//     }
//     return 0;
// }