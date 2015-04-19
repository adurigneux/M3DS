#version 130

in vec3 position; // Eye Coordinates
//in vec3 color;
in vec3 normal;

out vec3 fColor;

uniform mat4 projection;
uniform mat4 transform;
uniform vec3 lightPosition;
uniform vec3 diffuseColor;

void main() {



    vec4 eyePosition=vec4(position,1); // passage en coordonnées homogènes

    eyePosition=transform*eyePosition;
    vec4 clipPosition=projection*eyePosition; // transformation par la matrice de projection

    gl_Position=clipPosition; // gl_Position doit être donné en clip coordinates


    vec3 N=normalize(normal);
    vec3 L=normalize(lightPosition - position);

    float intensity = max(dot(N,L),0.0);


    fColor=intensity*diffuseColor;




}
