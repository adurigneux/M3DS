#version 130

uniform sampler2D image1;

in vec4 fTexCoord;

out vec4 fragColor;

void main() {
  vec4 texCoord=fTexCoord;



  texCoord.xyz/=texCoord.w; // clip coordinates => ndc

  texCoord.xy += 1.0;
  texCoord.xy /= 2.0;

  fragColor=texture(image1,texCoord.xy);
}
