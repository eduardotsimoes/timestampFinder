

#include "argumentParser.hpp"
#include <string.h>
#include <iostream>

bool argumentParser( int argc , char* argv[], context &cnt) {

    if (argc < 3 ){
        std::cout<< " error, arguments must be higher than 1 " << "\n";
        return false;
    } else {
        for (int i=1; i < argc-1 ; ++i){
            
            //std::cout<< " Index : "<< i << " value: " << argv[i] << "\n";

            if (strcmp(argv[i],"top")==0) {
                
                cnt.mode=1;
                //std::cout<< "--> top : arg "<< argv[++i] << "\n";
                cnt.numberOfTopQueries = std::stoi(argv[++i]);

            } else if (strcmp(argv[i],"distinct")==0) {
                cnt.mode=2; 
                //std::cout<< "--> distinct "<< "\n";
            
            } else if (strcmp(argv[i],"--from")==0) {
                cnt.from = std::stoi(argv[++i]);
                //std::cout<< "--> --from : arg "<< argv[++i] << "\n";
            } else if (strcmp(argv[i],"--to")==0) {
                cnt.to = std::stoi(argv[++i]);
                //std::cout<< "--> --to : arg "<< argv[++i] << "\n";
            } else {
                std::cout<< " unknown arguments. Index : "<< i << " value: " << argv[i] << "\n";
                return false;
            }
            
        }
        cnt.fileName = argv[argc-1];
        //std::cout<< "--> filename : "<< argv[argc-1] << "\n";
        //std::cout << "\n\n";
    }

    return true;


}