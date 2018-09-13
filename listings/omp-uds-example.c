void myDynInit(){}
void myDynNext(){}
void myDynFini(){}

void example() {
    #pragma omp declare schedule(my_dynamic) init(myDynInit) next(myDynNext) fini(myDynFini)
    static schedule_data sd; 
    int chunkSize = 4;
    #pragma omp parallel for schedule(my_dynamic:chunkSize,&sd)
    for(int i = 0; i < n; i++)
        c[i] = a[i]*b[i];
}
