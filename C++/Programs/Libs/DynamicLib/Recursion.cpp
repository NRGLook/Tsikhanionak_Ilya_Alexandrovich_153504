extern "C" __declspec(dllexport) bool elementExist(int* array, int temp, int i)
{
    //��������� ������� ����� �� ����� �� ������� �������
    if (i < temp) return false;

    //���������� ������� �������� (������� ��� ������� ����������)
    if (array[i] <= i * i) return true;

    //��������� ���������� ������� (��� false-��������� ����������)
    else return elementExist(array, temp, i - 1);
}