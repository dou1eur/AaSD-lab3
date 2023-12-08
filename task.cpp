#include "sorts.cpp"

using namespace std;

int main(){
    std::vector<int> v1{3,0,2,1,5,9,7};
    std::vector<int> v2{3,0,2,1,5,9,7};
    std::vector<int> v3{3,0,2,1,5,9,7};
    insertion(v1);
    qsort(v2,v2.size());
    //merge_sort(v3);
    cout<<"Check sorts: "<<endl;
    cout<<"Insert: "<<endl;
    for(int i=0;i<v1.size();++i){
        cout<<v1[i]<<" "<<endl;
    }
    cout<<"Qick: "<<endl;
    for(int i=0;i<v2.size();++i){
        cout<<v2[i]<<" "<<endl;
    }
    //cout<<"Merge: "<<endl;
    //for(int i=0;i<v3.size();++i){
        //cout<<v3[i]<<" "<<endl;
    //}
}
