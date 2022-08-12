#ifndef WINDOWSWITCH_H
#define WINDOWSWITCH_H

template <class A, class B>
void SwitchW(A* ptr) {
B *window = new B;
window->show();
ptr->close();
}

#endif // WINDOWSWITCH_H
