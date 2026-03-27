typedef struct ScoreNode
{
        int score;
        struct ScoreNode* next;
}n;

typedef struct StudentNode
{
        char name[100];
        struct Score* scores;
        struct StudentNode* next;
}m;


m* CreateStd(const char* );
void Addstd(m** , const char* );
n* CreateScore(int );
void AddScore(m* , int );
void EnterScores(m* );
void PrintStdAndScores(m* );
void freestd( );
