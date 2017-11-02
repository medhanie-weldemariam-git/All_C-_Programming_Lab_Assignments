#include <iostream>
#include <set>
#include <map>
#include <list>
#include <tuple>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <algorithm>

//g++11 -std=c++11 new_stat_tool.cc

using namespace std;

using age = vector<int>;
using name_age_tup = tuple <string,age>;
using name_age_list = list <name_age_tup>;
using name_age_map = map <string,vector<int>>;
using all_column = tuple<string,int,double,int>;
using list_all = list<all_column>;


const string flags[] = {"--name","--count","--average","--median"};

istringstream streamflag;

void read_print_file (const string &flag,istream &my_stream)
{
    int age;
    int list_amount=0;
    int median;
    string name;
    string all_input;
    float average_ages=0;
    int maximum_list{20000};
    unsigned int name_size_max=0;
    istringstream iss;
    name_age_map list_all_people;
    list <all_column> people_list;


    while (getline(my_stream,all_input) && (list_amount<maximum_list))

    {
        iss.str(all_input);
        if (!( iss >> name))
        {
            cout<<"Invalid name";
        }
        else if (!(iss >> age))
        {
            cout<<"Invalid age";
        }
        else
        {
            list_all_people[name].push_back(age);
            if (name.length()>name_size_max)
            {
                name_size_max = name.length();
            }
        }
        iss.clear();
        list_amount++;

    }

    for (auto itr = list_all_people.begin(); itr != list_all_people.end(); itr++)
    {

        for_each (itr -> second.begin(),itr -> second.end(),[&](int age){average_ages +=age;});
        average_ages = average_ages / itr -> second.size();
        sort (itr -> second.begin(),itr -> second.end());
        if  (itr -> second.size() % 2)
        {
            median  = itr -> second.at(((itr -> second.size()/2)));
        }
        else
        {
            median  = itr -> second.at(((itr -> second.size()/2)-1));
        }
        people_list.push_back(make_tuple(itr -> first,itr -> second.size(),average_ages,median));
        average_ages=0;
    }

    people_list.sort ([&](const all_column &l,const all_column &r)
    {
        if (flag == flags[0])
        {
            return get<0>(l) < get<0>(r);
        }
        else if (flag == flags[1]  )
        {
            return get<1>(l) < get<1>(r);
        }
        else if (flag == flags[2]  )
        {
            return get<2>(l) < get<2>(r);
        }
        else
        {
            return get<3>(l) < get<3>(r);
        }
    });

    name_size_max+=2;

    cout << left << setw(name_size_max) << "Name" << right << setw(6) << "Count" << setw(14) << "Average" << setw(7) << "Median" << endl;

    for(list_all::const_iterator it_list = people_list.begin(); it_list != people_list.end(); it_list++)
       {
          cout << left   << setw( name_size_max)  << get<0>(*it_list) << right << setw(5) << get<1>(*it_list) << right << setw(12) << setprecision(1) <<  fixed    << get<2>(*it_list) << right <<setw(6) << get<3>(*it_list) << endl;
       }
}

int main(int argc, char* argv[])
{
    string filename= "";
    string flag="";

    if(argc == 2)
    {
        filename=argv[1];
    }

    else if (argc == 3)
    {
        filename=argv[2];
        flag=argv[1];


        if ( (flag != flags[0] ) &&  (flag != flags[1]) && ( flag  != flags[2]) &&  ( flag  != flags[3]  ))
        {
            cout<<"Invalid number of arguments is incorrect.";
            throw invalid_argument("Faulty in the arguments in the command line");
        }
    }
    else
    {
        cout<<"Error, Invalid number of arguments!!!"<<endl;
        throw invalid_argument("Faulty in the arguments in the command line");
        exit (0);
    }
    ifstream stream_filename;
    stream_filename.open(filename);

    if (!(stream_filename.is_open()))
    {
        cout<<"File can not be opened.";
        throw ios::failure("File open failed.");
        return 0;
    }
    else
    {
        stream_filename.close();
        stream_filename.clear();
    }

    ifstream myfile(filename);

    read_print_file (flag,myfile);

}
