#include "light_source.h"

light_source::light_source(GLenum number) {
    _num = number;
}

~void LightSource::~LightSource();

bool getState::getState(){
    return _state;
}

bool setState(bool state){

    _state=state;
    return _state;
}

GLenum getNum(){
    return _num;
}

setPosition(const Vector4 & position){
    _position = position;
}

setDirection(const Vector3 & direction){
    _direction = direction;
}

setCutOff(double cut_off){
    _cut_off = cut_off;
}

setExponent(double exponent){
    _exponent = exponent;
}

setDiffuse(const Vector4 diffuse){
    _diffuse = diffuse;
}

setSpecular(const Vector4 specular){
    _specular = specular;
}

draw();

