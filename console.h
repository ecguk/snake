#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

namespace console {

// ȭ�鿡 ��� ������ �ִ� �ʺ�
const int SCREEN_WIDTH = 25;
// ȭ�鿡 ��� ������ �ִ� ����
const int SCREEN_HEIGHT = 25;

// console ���̺귯���� �ʱ�ȭ �Ѵ�. ���� ���� ���� ������ �ѹ��� ȣ���ؾ� �Ѵ�.
void init();

// ȭ���� �����ϰ� 60 FPS�� ���߱� ���� ���� ������ �ð����� ����Ѵ�.
// �� ���� ������ �������� ȣ���ؾ� �Ѵ�.
void wait();

// x, y ��ġ�� ���ڿ� s�� �׸���.
void draw(int x, int y, const char *s);

// x, y ��ġ�� ���ڿ� s�� �׸���.
void draw(int x, int y, std::string s);

// ȭ�鿡 �׷��� ���� ���� �����.
// �ʿ信 ���� �� ���� ������ ���� �κп��� ȣ�� �� �� �ִ�.
void clear();

// K_LEFT: ���� ����Ű
// K_RIGHT: ������ ����Ű
// K_UP: ���� ����Ű
// K_DOWN: �Ʒ��� ����Ű
// K_ESC: ESC
// K_ENTER: ����
// K_OTHER: ���� Ű�� �̿��� Ű
enum Key { K_NONE = 0, K_OTHER, K_LEFT, K_RIGHT, K_UP, K_DOWN, K_ESC, K_ENTER };

// Ű�� ���ȴ��� Ȯ���Ѵ�.
bool key(Key k);

} // namespace console

#endif