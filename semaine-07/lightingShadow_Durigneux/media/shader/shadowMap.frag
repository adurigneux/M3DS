#version 130

uniform sampler2D depthTexture ;

in vec4 fTexCoord;

out vec4 fragColor;

void main() {
    vec4 texCoord=fTexCoord;



    texCoord.xyz/=texCoord.w; // clip coordinates => ndc

    texCoord.xyz += 1.0;
    texCoord.xyz /= 2.0;

    //fragColor=texture(depthTexture ,texCoord.xy);
    //fragColor=1.0-clamp(50.0*(1.0-fragColor),0,1);

    if(texCoord.z>=0.0){
        if(texCoord.z-0.001>texture(depthTexture,texCoord.xy).z){
            fragColor=vec4(0,0,0,0.6);
        }
        else {
            fragColor=vec4(0,0,0,0);
        }
    }
    else {
        fragColor=vec4(0,0,0,0);
    }

}
