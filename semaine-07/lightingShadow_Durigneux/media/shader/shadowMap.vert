#version 130

in vec3 position;

uniform mat4 modelviewMatrix;
uniform mat4 mvp;
uniform mat4 textureEyeMatrix; // passage Texture->Eye

out vec4 fTexCoord;

void main() {

  vec4 positionEye=modelviewMatrix*vec4(position,1.0);

  fTexCoord=vec4(0.0,0.0,0.0,1.0); // les coordonnées de texture de chaque sommet sont calculées (ici, initialisation à 0)

  gl_Position=mvp*vec4(position,1.0);
  fTexCoord=gl_Position;
  fTexCoord=positionEye;
  fTexCoord=textureEyeMatrix*positionEye;

}
