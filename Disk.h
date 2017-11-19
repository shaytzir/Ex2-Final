//
// Shay Tzirin
// ID: 315314930
//

#ifndef EX2_DISK_H
#define EX2_DISK_H
class Disk {
public:
    /*
     * empty constructor, just sets it to be ' '
     */
    Disk();
    /**
     * constructor.
     * @param newSign the sign of the given cell
     * @param diskRow
     * @param diskCol
     */
    Disk(char newSign, int diskRow, int diskCol);
    /**
     * setter
     * @param newSign new sign for the given cell
     */
    void setSign(char newSign);
    /**
     *
     * @return the sign of the current disk
     */
    char getSign();

private:
    char sign_;
    int row_;
    int col_;
};



#endif //EX2_DISK_H
