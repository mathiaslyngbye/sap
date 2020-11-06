#include <iostream>
#include <string>
#include <vector>

class Sap
{
    public:
        Sap(int argc, char* argv[])
        {
            initialise(argc, argv);
            std::cout << "Size of argument tree: " << argument_tree.size() << std::endl;
        }
        void getArgs(std::vector<std::string> &arguments, std::string flag)
        {
            for(size_t i = 0; i < argument_tree.size(); i++)
            {
                if(argument_tree[i].flag == flag)
                {
                    arguments = argument_tree[i].entries;
                    break;
                }
            }
        }
    private:
        
        // Structs
        struct node
        {
            std::string flag;
            std::vector<std::string> entries;
        };
        
        // Variables
        std::vector<node> argument_tree;

        // Methods
        int initialise(int argc, char* argv[])
        {
            std::string argument_string;
            node current_node;
            for(size_t i = 1; i < argc; i++)
            {
                argument_string = argv[i];

                if(isFlag(argument_string))
                {
                    current_node = { argument_string, {} };
                    i++;
                }

                while(i < argc)
                {
                    argument_string = argv[i];
                    if(!isFlag(argument_string))
                    {
                        std::cout << current_node.flag << " <- " << argument_string << std::endl;
                        current_node.entries.push_back(argument_string);
                        i++;
                    }
                    else
                    {
                        i--;
                        break;
                    }
                } 
                argument_tree.push_back(current_node);
            }
        }

        bool isFlag(std::string entry)
        {
            if(entry.find('-', 0) == 0)
                return true;
            else
                return false;
        }

};
