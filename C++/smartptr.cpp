#include<iostream>
#include<string>
#include<memory>

class Report{
    public:
    Report(const std::string s) : str(s)
    {
        std::cout <<"Object Created!\n";
    }
    ~Report()
    {
        std::cout <<"Object deleted!\n";
    }
    void comment() const
    {
        std::cout <<str <<"\n";
    }
    private:
    std::string str;
};

int main()
{
    {
        std::auto_ptr<Report> ps (new Report("using auto_ptr"));
        ps->comment();
    }

    {
        std::shared_ptr<Report> ps (new Report("using shared_ptr"));
        ps->comment();
    }

    {   
        std::unique_ptr<Report>  ps(new Report("Using unique_ptr"));
        ps->comment();
    }
    return 0;

}