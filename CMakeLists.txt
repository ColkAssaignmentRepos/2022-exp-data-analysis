cmake_minimum_required(VERSION 3.22)
project(2022_exp_data_analysis_ C)

set(CMAKE_C_STANDARD 17)

add_executable(2022_exp_data_analysis
        # Uncomment the next line if you want to compile "1".
        # src/01/main.c src/common/type/linearDouble.c src/common/statics/staticalFunctions.c src/common/utils/readFile.c)
        #
        # Uncomment the next line if you want to compile "2".
        # src/02/main.c src/02/linearApproximation.c src/common/type/linearDouble.c src/common/statics/staticalFunctions.c src/common/utils/readFile.c)
        #
        # Uncomment the next line if you want to compile "3".
        # src/03/main.c src/03/quadraticApproximation.c src/common/type/linearDouble.c src/common/statics/staticalFunctions.c src/common/utils/readFile.c)
        #
        # Uncomment the next line if you want to MAKE ALL THE CODE LOADED. ( Recommended ONLY FOR an IDE or a language server )
        src/01/main.c src/02/main.c src/common/type/linearDouble.h src/common/utils/readFile.h src/common/macro/myErrors.h src/01/main.c src/common/type/linearDouble.c src/common/utils/readFile.c src/common/macro/printFormat.h src/common/type/linearFunctionParameters.h src/02/linearApproximation.c src/common/type/quadraticFunctionParameters.h src/03/quadraticApproximation.c src/common/statics/staticalFunctions.c src/common/statics/staticalFunctions.h src/03/main.c)
