const modal = document.querySelector(".modal");
const overlay = document.querySelector(".overlay");
const openModalBtn = document.querySelector(".btn-open");
const closeModalBtn = document.querySelector(".btn-close");
const body = document.querySelector("body");
const closeModal = function () {
  modal.classList.add("hidden");
  overlay.classList.add("hidden");
  body.style.overflow = "auto";
};

closeModalBtn.addEventListener("click", closeModal);
overlay.addEventListener("click", closeModal);

document.addEventListener("keydown", function (e) {
  if (e.key === "Escape" && !modal.classList.contains("hidden")) {
    closeModal();
  }
});

const openModal = function () {
  modal.classList.remove("hidden");
  overlay.classList.remove("hidden");
  body.style.overflow = "hidden";
  const curr = document.documentElement.scrollTop || document.body.scrollTop;
  console.log(curr);
  document.documentElement.style.setProperty("--top-margin", curr + "px");
};

openModalBtn.addEventListener("click", openModal);
