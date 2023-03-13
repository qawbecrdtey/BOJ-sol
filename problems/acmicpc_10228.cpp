/** FUNCTION IMPLEMENTATION PROBLEM **/
#include "grader.h"
#include "memory.h"

void play() {
    char a[51];
    bool visited[51]{};
    for(int i = 1; i <= 50; i++) a[i] = faceup(i);
    for(int i = 1; i <= 50; i++) {
        if(visited[i]) continue;
        for(int j = i + 1; j <= 50; j++) {
            if(a[i] == a[j]) {
                faceup(i);
                faceup(j);
                visited[i] = visited[j] = true;
                break;
            }
        }
    }
}