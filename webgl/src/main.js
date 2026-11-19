import * as THREE from 'three';

const canvas = document.querySelector('#stadium');
const errorBox = document.querySelector('#error');
const scene = new THREE.Scene();
scene.background = new THREE.Color(0x091522);
scene.fog = new THREE.Fog(0x091522, 105, 230);

const camera = new THREE.PerspectiveCamera(42, 1, 0.1, 500);
const renderer = new THREE.WebGLRenderer({ canvas, antialias: true, powerPreference: 'high-performance' });
renderer.setPixelRatio(Math.min(window.devicePixelRatio || 1, 2));
renderer.shadowMap.enabled = true;
renderer.shadowMap.type = THREE.PCFSoftShadowMap;
renderer.outputColorSpace = THREE.SRGBColorSpace;
renderer.toneMapping = THREE.ACESFilmicToneMapping;
renderer.toneMappingExposure = 1.18;

const world = new THREE.Group();
scene.add(world);

const mats = {
  turf: new THREE.MeshStandardMaterial({ color: 0x2d854c, roughness: 0.95 }),
  stripe: new THREE.MeshStandardMaterial({ color: 0x347e4a, roughness: 1 }),
  line: new THREE.MeshBasicMaterial({ color: 0xe9f1df }),
  concrete: new THREE.MeshStandardMaterial({ color: 0x64727a, roughness: 0.88 }),
  darkConcrete: new THREE.MeshStandardMaterial({ color: 0x263640, roughness: 0.9 }),
  seatA: new THREE.MeshStandardMaterial({ color: 0x174f80, roughness: 0.72 }),
  seatB: new THREE.MeshStandardMaterial({ color: 0x1c638f, roughness: 0.72 }),
  roof: new THREE.MeshStandardMaterial({ color: 0x263b48, metalness: 0.38, roughness: 0.55, side: THREE.DoubleSide }),
  metal: new THREE.MeshStandardMaterial({ color: 0xb8c7ca, metalness: 0.72, roughness: 0.28 }),
  goal: new THREE.MeshStandardMaterial({ color: 0xe6e9e4, roughness: 0.45 }),
  wood: new THREE.MeshStandardMaterial({ color: 0x96704a, roughness: 0.82 }),
  board: new THREE.MeshStandardMaterial({ color: 0x122a38, emissive: 0x0b2630, emissiveIntensity: 0.6 }),
  red: new THREE.MeshStandardMaterial({ color: 0xc94b43 }),
  blue: new THREE.MeshStandardMaterial({ color: 0x315cbd }),
  black: new THREE.MeshStandardMaterial({ color: 0x101820 })
};

function mesh(geometry, material, parent = world, position = [0,0,0]) {
  const object = new THREE.Mesh(geometry, material);
  object.position.set(...position);
  object.castShadow = true;
  object.receiveShadow = true;
  parent.add(object);
  return object;
}
function box(parent, size, position, material, cast = true) {
  const object = mesh(new THREE.BoxGeometry(...size), material, parent, position);
  object.castShadow = cast;
  return object;
}
function cylinder(parent, radiusTop, radiusBottom, height, position, material, segments = 10) {
  return mesh(new THREE.CylinderGeometry(radiusTop, radiusBottom, height, segments), material, parent, position);
}
function line(points, material = mats.line, radius = 0.045) {
  const curve = new THREE.CatmullRomCurve3(points.map(p => new THREE.Vector3(...p)));
  return mesh(new THREE.TubeGeometry(curve, Math.max(16, points.length * 4), radius, 5, false), material);
}
function makePitch() {
  box(world, [44, 0.7, 25], [0, -0.55, 0], mats.darkConcrete);
  box(world, [41, 0.12, 21], [0, -0.12, 0], mats.turf);
  for (let i = 0; i < 10; i++) {
    const x = -18.45 + i * 4.1;
    box(world, [2.05, 0.012, 20.8], [x, -0.052, 0], i % 2 ? mats.stripe : mats.turf, false);
  }
  const y = 0.0;
  const outline = [[-19.5,y, -9.5],[19.5,y,-9.5],[19.5,y,9.5],[-19.5,y,9.5],[-19.5,y,-9.5]];
  line(outline, mats.line, 0.055);
  line([[0,y,-9.5],[0,y,9.5]], mats.line, 0.045);
  const circle = [];
  for(let i=0;i<=96;i++){const a=i/96*Math.PI*2;circle.push([4.2*Math.cos(a),y+0.012,4.2*Math.sin(a)]);}
  line(circle,mats.line,0.045);
  cylinder(world,0.075,0.075,0.035,[0,0.02,0],mats.line,12);
  for(const sign of [-1,1]){
    box(world,[5.8,0.012,0.045],[sign*14.1,0.012,0],mats.line,false);
    box(world,[0.045,0.012,10.2],[sign*19.5,0.012,0],mats.line,false);
    box(world,[0.045,0.012,10.2],[sign*14.1,0.012,0],mats.line,false);
    box(world,[5.8,0.012,0.045],[sign*16.8,0.012,0],mats.line,false);
    box(world,[5.8,0.012,0.045],[sign*16.8,0.012,0],mats.line,false);
    box(world,[0.045,0.012,3.7],[sign*14.1,0.012,0],mats.line,false);
    box(world,[0.045,0.012,3.7],[sign*19.5,0.012,0],mats.line,false);
    const spot = mesh(new THREE.CircleGeometry(0.08,12),mats.line,world,[sign*14.1,0.025,0]);
    spot.rotation.x=-Math.PI/2;
  }
}
function makeGoal(x, direction) {
  const group = new THREE.Group(); world.add(group); group.position.set(x,0,0);
  const z = direction * 0.0;
  const w=3.1,h=2.15,d=1.8;
  const postMat=mats.goal;
  cylinder(group,0.075,0.075,h,[0,h/2,0],postMat,10);
  cylinder(group,0.075,0.075,h,[-w,h/2,0],postMat,10);
  cylinder(group,0.075,0.075,w,[-w/2,h,0],postMat,10).rotation.z=Math.PI/2;
  const netMat=new THREE.LineBasicMaterial({color:0xc8d5d2,transparent:true,opacity:.6});
  for(let i=0;i<=12;i++){
    const xx=-w+i*w/12;
    const g=new THREE.BufferGeometry().setFromPoints([new THREE.Vector3(xx,0,0),new THREE.Vector3(xx, h, -direction*d)]);
    const o=new THREE.Line(g,netMat);group.add(o);
  }
  for(let j=0;j<=6;j++){
    const yy=j*h/6;
    const g=new THREE.BufferGeometry().setFromPoints([new THREE.Vector3(-w,yy,-direction*d),new THREE.Vector3(0,yy,-direction*d)]);
    group.add(new THREE.Line(g,netMat));
  }
  cylinder(group,0.035,0.035,d,[0,h/2,-direction*d/2],postMat,8).rotation.x=Math.PI/2;
}
function makeStands() {
  const rows=11, seatWidth=.58, seatDepth=.52;
  for (const side of [-1,1]) {
    const stand = new THREE.Group(); world.add(stand);
    stand.position.z=side*13.2;
    for(let r=0;r<rows;r++){
      const y=.25+r*.72, z=side*(r*.72);
      box(stand,[46,.28,.92],[0,y,z],mats.concrete);
      for(let s=0;s<68;s++){
        const x=-22+s*.65;
        const seatMat=(s+r)%5===0?mats.seatB:mats.seatA;
        box(stand,[seatWidth,.32,seatDepth],[x,y+.24,z+side*.02],seatMat);
        box(stand,[seatWidth,.08,.12],[x,y+.52,z+side*.18],seatMat);
      }
    }
    box(stand,[48,.5,1.4],[0,8.1,side*8.2],mats.darkConcrete);
    // Upper fascia and roof canopy.
    box(stand,[49,.55,1.1],[0,8.9,side*8.8],mats.roof);
    const canopy=mesh(new THREE.BoxGeometry(49,.28,9),mats.roof,stand,[0,10.2,side*4.8]);
    canopy.rotation.x=side*.08;
    for(let x=-22;x<=22;x+=11){
      box(stand,[.28,2.8,.28],[x,9.0,side*8.4],mats.metal);
    }
  }
  for (const side of [-1,1]) {
    const stand = new THREE.Group(); world.add(stand); stand.rotation.y=Math.PI/2; stand.position.x=side*22.6;
    for(let r=0;r<8;r++){
      const y=.2+r*.72,z=side*r*.72;
      box(stand,[25,.3,.9],[0,y,z],mats.concrete);
      for(let s=0;s<36;s++){
        const x=-12+s*.7;
        box(stand,[.62,.32,.5],[x,y+.22,z+side*.02],(s+r)%6===0?mats.seatB:mats.seatA);
      }
    }
    box(stand,[26,.55,1.1],[0,6.4,side*5.8],mats.roof);
  }
}
function makeDetails() {
  // Corner towers and floodlight banks.
  for(const x of [-23.5,23.5]) for(const z of [-13,13]){
    cylinder(world,.12,.22,12,[x,6,z],mats.metal,8);
    box(world,[3.6,.45,.45],[x,12,z],mats.metal);
    for(let i=0;i<5;i++) for(let j=0;j<2;j++){
      const bulb=mesh(new THREE.BoxGeometry(.38,.22,.12),new THREE.MeshBasicMaterial({color:0xfff0c4}),world,[x-1.3+i*.65,12.25,z+(j-.5)*.28]);
    }
  }
  // Goals at both ends.
  makeGoal(-20.1,-1); makeGoal(20.1,1);
  // Dugouts / benches.
  for(const z of [-12.4,12.4]){
    box(world,[10,.18,1.2],[0,.15,z],mats.darkConcrete);
    for(let i=0;i<8;i++) box(world,[.85,.7,.5],[-3.5+i, .58,z],mats.wood);
    box(world,[10,.12,1.4],[0,1.2,z],mats.roof);
    for(let x=-4.5;x<=4.5;x+=3) box(world,[.12,1.15,.12],[x,.65,z],mats.metal);
  }
  // Scoreboard.
  box(world,[7,3,.5],[-4,15,-18],mats.darkConcrete);
  box(world,[6.5,2.5,.12],[-4,15,-17.68],mats.board);
  const scoreText = document.createElement('canvas');scoreText.width=512;scoreText.height=192;
  const ctx=scoreText.getContext('2d');ctx.fillStyle='#102d3a';ctx.fillRect(0,0,512,192);
  ctx.fillStyle='#9be5bd';ctx.font='bold 42px Arial';ctx.textAlign='center';ctx.fillText('HOME   0  —  0   AWAY',256,82);
  ctx.font='24px Arial';ctx.fillStyle='#d5e3e6';ctx.fillText('MATCH DAY  •  90:00',256,137);
  const tex=new THREE.CanvasTexture(scoreText);tex.colorSpace=THREE.SRGBColorSpace;
  const screen=mesh(new THREE.PlaneGeometry(6.2,2.3),new THREE.MeshBasicMaterial({map:tex}),world,[-4,15,-17.59]);
  // Advertising boards around the pitch.
  for(let x=-17;x<=17;x+=8.5){
    box(world,[7.5,.65,.22],[x,.38,-10.8],mats.board);
    box(world,[7.5,.65,.22],[x,.38,10.8],mats.board);
  }
  // Small flags on the corners.
  for(const x of [-20,20])for(const z of [-10,10]){
    cylinder(world,.025,.035,1.8,[x,.9,z],mats.goal,8);
    const flag=mesh(new THREE.PlaneGeometry(.75,.42),x<0?mats.red:mats.blue,world,[x+.35,1.55,z]);
  }
}
function makeGround() {
  const ground=mesh(new THREE.PlaneGeometry(180,180),new THREE.MeshStandardMaterial({color:0x182b34,roughness:1}),world,[0,-.95,0]);
  ground.rotation.x=-Math.PI/2;ground.receiveShadow=true;ground.castShadow=false;
}
makeGround();makePitch();makeStands();makeDetails();

scene.add(new THREE.HemisphereLight(0xb7d8e8,0x26323a,1.45));
const ambient=new THREE.AmbientLight(0xffffff,.34);scene.add(ambient);
const sun=new THREE.DirectionalLight(0xffe4bd,2.1);sun.position.set(-35,65,30);sun.castShadow=true;
sun.shadow.mapSize.set(2048,2048);sun.shadow.camera.left=-65;sun.shadow.camera.right=65;sun.shadow.camera.top=65;sun.shadow.camera.bottom=-65;sun.shadow.bias=-.0002;scene.add(sun);
const spotlight=new THREE.SpotLight(0xd8edff,900,130,Math.PI/5,.5,1.4);
spotlight.castShadow=true;spotlight.shadow.mapSize.set(1024,1024);scene.add(spotlight);scene.add(spotlight.target);
const fill=new THREE.PointLight(0x79a9c4,45,90);fill.position.set(0,28,0);scene.add(fill);

let cameraHeight=70,cameraDistance=50,angle=0,lightAngle=0,mode='solid',dragging=false,lastX=0,lastY=0;
function updateCamera(){
  camera.position.set(cameraDistance*Math.cos(angle),cameraHeight,cameraDistance*Math.sin(angle));
  camera.lookAt(0,2,0);
  spotlight.position.set(26*Math.cos(lightAngle),24,26*Math.sin(lightAngle));
  spotlight.target.position.set(0,0,0);
}
updateCamera();

const heightInput=document.querySelector('#height'),distanceInput=document.querySelector('#distance'),lightInput=document.querySelector('#light');
function bindRange(input,fn,output,format=v=>v){input.addEventListener('input',()=>{const v=Number(input.value);fn(v);output.textContent=format(v);updateCamera();});}
bindRange(heightInput,v=>cameraHeight=v,document.querySelector('#heightValue'));
bindRange(distanceInput,v=>cameraDistance=v,document.querySelector('#distanceValue'));
bindRange(lightInput,v=>lightAngle=v*Math.PI/180,document.querySelector('#lightValue'),v=>v+'°');
function setMode(next){
  mode=next;
  document.querySelectorAll('[data-mode]').forEach(b=>b.classList.toggle('active',b.dataset.mode===mode));
  world.traverse(o=>{if(o.isMesh){const matsArray=Array.isArray(o.material)?o.material:[o.material];matsArray.forEach(m=>{if('wireframe'in m)m.wireframe=mode==='wire';});}});
  // Point mode is represented by a lightweight points overlay on the stadium mesh.
  if(mode==='points'){
    world.traverse(o=>{if(o.isPoints)o.visible=true;});
    world.traverse(o=>{if(o.isMesh){o.userData.oldVisible=o.visible;o.visible=false;}});
    if(!world.userData.pointsGroup){
      const group=new THREE.Group();world.add(group);
      world.traverse(o=>{if(o.isMesh&&o.geometry&&!o.userData.noPoints){const p=new THREE.Points(o.geometry,new THREE.PointsMaterial({color:0x9ce5bd,size:.12}));p.position.copy(o.position);p.rotation.copy(o.rotation);p.scale.copy(o.scale);group.add(p);}});
      world.userData.pointsGroup=group;
    }
    world.userData.pointsGroup.visible=true;
  } else {
    world.traverse(o=>{if(o.isMesh&&o.userData.oldVisible!==undefined){o.visible=o.userData.oldVisible;delete o.userData.oldVisible;}});
    if(world.userData.pointsGroup)world.userData.pointsGroup.visible=false;
  }
}
document.querySelectorAll('[data-mode]').forEach(b=>b.addEventListener('click',()=>setMode(b.dataset.mode)));
document.querySelector('#reset').addEventListener('click',()=>{
  cameraHeight=70;cameraDistance=50;angle=0;lightAngle=0;
  heightInput.value=70;distanceInput.value=50;lightInput.value=0;
  document.querySelector('#heightValue').textContent='70';document.querySelector('#distanceValue').textContent='50';document.querySelector('#lightValue').textContent='0°';updateCamera();
});
canvas.addEventListener('pointerdown',e=>{dragging=true;lastX=e.clientX;lastY=e.clientY;canvas.setPointerCapture(e.pointerId);});
canvas.addEventListener('pointerup',()=>dragging=false);canvas.addEventListener('pointercancel',()=>dragging=false);
canvas.addEventListener('pointermove',e=>{if(!dragging)return;angle-=(e.clientX-lastX)*.006;cameraHeight=Math.max(8,Math.min(105,cameraHeight+(e.clientY-lastY)*.18));lastX=e.clientX;lastY=e.clientY;heightInput.value=cameraHeight;document.querySelector('#heightValue').textContent=Math.round(cameraHeight);updateCamera();});
canvas.addEventListener('wheel',e=>{e.preventDefault();cameraDistance=Math.max(25,Math.min(110,cameraDistance+e.deltaY*.035));distanceInput.value=cameraDistance;document.querySelector('#distanceValue').textContent=Math.round(cameraDistance);updateCamera();},{passive:false});
window.addEventListener('keydown',e=>{
  const k=e.key.toLowerCase();
  if(k==='1')setMode('wire');if(k==='2')setMode('solid');if(k==='3')setMode('points');
  if(k==='a')angle+=.08;if(k==='d')angle-=.08;
  if(k==='w')cameraDistance=Math.min(110,cameraDistance+1);if(k==='s')cameraDistance=Math.max(25,cameraDistance-1);
  if(k==='r')cameraHeight=Math.min(105,cameraHeight+1);if(k==='f')cameraHeight=Math.max(8,cameraHeight-1);
  if(k==='j')lightAngle+=.08;if(k==='l')lightAngle-=.08;
  if(k==='i')spotlight.intensity=Math.min(1800,spotlight.intensity+40);if(k==='k')spotlight.intensity=Math.max(0,spotlight.intensity-40);
  if(k==='y')spotlight.angle=Math.max(.08,spotlight.angle-.025);if(k==='h')spotlight.angle=Math.min(Math.PI/2,spotlight.angle+.025);
  heightInput.value=cameraHeight;distanceInput.value=cameraDistance;lightInput.value=((lightAngle*180/Math.PI)%360+360)%360;
  document.querySelector('#heightValue').textContent=Math.round(cameraHeight);document.querySelector('#distanceValue').textContent=Math.round(cameraDistance);document.querySelector('#lightValue').textContent=Math.round(lightInput.value)+'°';
  updateCamera();
});
function resize(){const w=canvas.clientWidth,h=canvas.clientHeight;renderer.setSize(w,h,false);camera.aspect=w/h;camera.updateProjectionMatrix();}
window.addEventListener('resize',resize);resize();
function animate(){requestAnimationFrame(animate);renderer.render(scene,camera);}
try{animate();}catch(err){errorBox.style.display='block';errorBox.textContent=err.message;console.error(err);}
if(!renderer.capabilities.isWebGL2){errorBox.style.display='block';errorBox.textContent='This browser does not support WebGL 2.';}
