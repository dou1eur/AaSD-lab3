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

    std::vector<int> v4{3,0,2,1,5,9,7};
    std::vector<int> v5{3,0,2,1,5,9,7};
    std::vector<int> v6{3,0,2,1,5,9,7};

    cout<<"Check Iterator: "<<endl<<"Insert sort"<<endl;
    stats s4=insertion(v4.begin(),v4.end());
    for(int i=0;i<v4.size();++i){
        cout<<v4[i]<<" "<<endl;
    }
    cout<<"Comparision count: "<<s4.comparison_count<<endl;
    cout<<"Copy count: "<<s4.copy_count<<endl;

    cout<<"Quick sort"<<endl;
    stats s5=quick_sort(v5.begin(),v5.end());
    for(int i=0;i<v5.size();++i){
        cout<<v5[i]<<" "<<endl;
    }
    cout<<"Comparision count: "<<s5.comparison_count<<endl;
    cout<<"Copy count: "<<s5.copy_count<<endl;
}
