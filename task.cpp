#include "sorts.cpp"

using namespace std;

int main(){
    std::vector<int> v1{3,0,2,1,5,9,7};
    std::vector<int> v2{3,0,2,1,5,9,7};
    std::vector<int> v3{3,0,2,1,5,9,7};
    stats s1=insertion(v1);
    stats s2=quick_sort(v2, v2.size());
    stats s3=merge_sort(v3);
    cout<<"Check sorts: "<<endl;
    cout<<"Insert: "<<endl;
    for(int i=0;i<v1.size();++i){
        cout<<v1[i]<<" "<<endl;
    }
    cout<<"Comparision count: "<<s1.comparison_count<<endl;
    cout<<"Copy count: "<<s1.copy_count<<endl;
    cout<<"Qick: "<<endl;
    for(int i=0;i<v2.size();++i){
        cout<<v2[i]<<" "<<endl;
    }
    cout<<"Comparision count: "<<s2.comparison_count<<endl;
    cout<<"Copy count: "<<s2.copy_count<<endl;
    cout<<"Merge: "<<endl;
    for(int i=0;i<v3.size();++i){
        cout<<v3[i]<<" "<<endl;
    }
    cout<<"Comparision count: "<<s3.comparison_count<<endl;
    cout<<"Copy count: "<<s3.copy_count<<endl;
}
