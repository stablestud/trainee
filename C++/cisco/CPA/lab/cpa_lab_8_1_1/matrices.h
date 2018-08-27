class matrix {
private:
        int container[2][2];
public:
        matrix(int v1, int v2, int v3, int v4)
        {
                container[0][0] = v1;
                container[0][1] = v2;
                container[1][0] = v3;
                container[1][1] = v4;
        }
        std::ostream& operator>> (std::ostream& o)
        {
                o << container[0][0] << " ";
                o << container[0][1] << std::endl;
                o << container[1][0] << " ";
                o << container[1][1] << " ";
                return o;
        }
};

std::ostream& operator<< (std::ostream& o, matrix& m)
{
        return m >> o;
}
