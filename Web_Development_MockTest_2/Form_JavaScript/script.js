const formData = {};

const form = document.querySelector("form");
form.addEventListener("submit", (e) => {
  document.querySelector("#alert").innerHTML = "";
  e.preventDefault();
  formData.name = e.target.querySelector("#name");
  formData.email = e.target.querySelector("#email");
  formData.phone = e.target.querySelector("#phone");
  formData.password = e.target.querySelector("#password");
  formData.confirmPassword = e.target.querySelector("#confirmPassword");
  formData.age = e.target.querySelector("#age");
  formData.date = e.target.querySelector("#date");
  formData.gender = e.target.querySelector("input[type=radio]:checked");
  formData.color = e.target.querySelector("#color");

  console.log(formData);
  let alert = document.querySelector("#alert");
  if (formData.name.value == "")
    alert.innerHTML += `<li>Name: field required</li>`;
  if (formData.email.value == "")
    alert.innerHTML += `<li>Email: field required</li>`;
  if (formData.phone.value == "")
    alert.innerHTML += `<li>Phone Number: field required</li>`;
  if (formData.password.value == "")
    alert.innerHTML += `<li>Password: field required</li>`;
  else if (formData.confirmPassword.value !== formData.password.value)
    alert.innerHTML += `<li>Password: is not matched</li>`;
  if (formData.age.value < 18)
    alert.innerHTML += `<li>Age sholud be 18 or more</li>`;
  if (formData.gender == null)
    alert.innerHTML += `<li>Gender: field required</li>`;
  if (formData.date.value == "")
    alert.innerHTML += `<li>Date: field required</li>`;
  if (formData.color.value == "")
    alert.innerHTML += `<li>Color: field required</li>`;

  if (alert.children.length == 0) {
    form.submit();
  }
});

function validateEmail(email) {
  if (/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(email)) {
    return true;
  }
  return false;
}
