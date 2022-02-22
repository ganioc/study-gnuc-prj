
namespace Nbk {
class Init{
    public:
        Init(){
            this->num = 1;
        }
        ~Init(){}
        void static init_dir(void);
    private:
        int num;
};


}