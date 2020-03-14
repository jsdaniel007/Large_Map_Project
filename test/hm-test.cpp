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

            printf("\n");

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

            // Now lets get hsum from all elements.
            int hmsum = 0;
            char buff[1024];
            start = clock();
            for (int i = 0; i < 26; i++) {
                buff[0] = 'a' + i;
                for (int j = 0; j < 26; j++) {
                    buff[1] = 'a' + j;
                    buff[2] = '\0';
                    hmsum += map.howMany(buff);
                }
            }
            diff = clock() - start;
            printf("hmsum = %d, sum = %d\n", hmsum, sum);
            printf("%d\n", diff);
            printf("howMany run in %f seconds\n", (diff*1.0)/CLOCKS_PER_SEC);

            // Our sum from hmsum should be the same and the number we put in.
            TS_ASSERT(hmsum == sum);

            printf("Test done...\n");
        }
};

