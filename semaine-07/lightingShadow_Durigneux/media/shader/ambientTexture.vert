#version 130
/**
  <c> F.Aubert Univ-Lille1
  **/

in vec3 position;
in vec2 texCoord;

uniform float repeat;

out vec4 fTexCoord;

uniform mat4 mvp;

void main(void) {
  fTexCoord=vec4(repeat,repeat,1.0,1.0)*vec4(texCoord.st,1.0,1.0); // 5* => to repeat texture image
  gl_Position=mvp*vec4(position,1.0);
}
