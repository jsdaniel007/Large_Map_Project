#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <time.h>
#include "map.hpp"
#include "ans1.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
    //const char[][] answers = {"test"};
        Map map;
    public:
        void validate(int len) {
            clock_t start = clock(), diff;
            int id;
            for (int i = 0; i < len; i++) {
                map.get(answers[i], id);
                TS_ASSERT(ids[i] == id);
            }
            diff = clock() - start;
            printf("Validated in %f seconds\n", (diff*1.0)/CLOCKS_PER_SEC);
        }

        void test1(void) {
            // First we grab all the names and put them into two vectors: first and last.
            FILE *fnames = fopen("firstnames.txt", "r");
            FILE *lnames = fopen("lastnames.txt", "r");
            std::vector<std::string> first;
            std::vector<std::string> last;
            char line[1024];

            while(fgets(line, 1024, fnames) != NULL) {
                line[strlen(line)-1] = '\0';
                first.push_back(line);
            }

            while(fgets(line, 1024, lnames) != NULL) {
                line[strlen(line)-1] = '\0';
                line[strlen(line)-1] = '\0';
                last.push_back(line);
            }

            fclose(fnames);
            fclose(lnames);

            printf("Number of first names:%d\n", first.size());
            printf("Number of last names:%d\n", last.size());

            // Now we add some of them to the map.
            int sum = 0;
            clock_t start = clock(), diff;
            for (int i = 0; i < first.size(); i++) {
                for (int j = 0; j < last.size(); j+= 50) {
                    sprintf(line, "%s %s", first[i].c_str(), last[j].c_str());
                    map.add(line, i*last.size() + j +1);
                    sum++;
                }
            }
            diff = clock() - start;

            // Report how long it took to build (not graded.)
            printf("%d\n", diff);
            printf("List with %d items was build in %f seconds\n", sum, (diff*1.0)/CLOCKS_PER_SEC);

            // Lets validate some of them.
            validate(1024);

            printf("Test done...\n");
        }
};

