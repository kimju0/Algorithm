class Player_20223908 : public PlayerFormat { // �̸� �ٲ��ֱ� Player_XXXXXXXX -> Player_�����й�
public:
    long StudentID = 20223908; // -------------�����й��� �� ������ �Ҵ�-------------

    Player_20223908() { // �̸� �ٲ��ֱ� Player_XXXXXXXX -> Player_�����й�
        setID(StudentID);
    }
    void decideBet(int round, const int numbers[], const int previousBets[]) {

        if(ARRAY_SIZE<2){
            setBet(round, 0);
            return;
        }

        int fir = 0, sec = -1;
        for (int j = 1; j < ARRAY_SIZE; j++) {
            double weight= numbers[j] / (double) previousBets[j] + 1;
            if (weight > numbers[fir] / (double) previousBets[fir] + 1) {
                sec = fir;
                fir = j;
            } else if (sec==-1||weight > numbers[sec] / (double) previousBets[sec] + 1) {
                sec = j;
            }
        }

        int bet = sec;
        setBet(round, bet);
    }
};
